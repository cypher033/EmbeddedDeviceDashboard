/*this one is a pre-processor directive that ensures the header file 
is included only once in a single compilation, preventing duplicate definitions.
is similar to #ifndef #define in C */
#pragma once 

/*
    Domain model: Commands (CORE)

    Goal:
    - Represent the user's intent to perform an action on a device
    without coupling to transport (serial/TCP) or UI (Qt).

    Key rules:
    - No infrastructure code here (no JSON parsing, no framing, no sockets).
    - Keep this file stable: adapters/services will depend on it.

    Replication pattern for other domain headers (config/alarm/telemetry):
    1) Strong IDs (Value Objects)  -> prevent mixing raw strings everywhere.
    2) Enums                        -> finite set of allowed types/states.
    3) Plain structs                -> easy to test and serialize later.
*/

#include "device_type.hpp"

#include <string>
#include <chrono>   
#include <utility>
/*this eed::core::domain are nested namespaces 'edd' embedded device dashboard  */
namespace edd::core::domain
{
    using Timestamp  =std::chrono::system_clock::time_point; //this is a type alias for a timestamp, using the system clock's time point like a typedef in C .


    // Strongly typed command identifier.
    // Implementation choice: string to allow UUIDs or human-readable IDs.
    struct CommandId
    {
        std::string value; //this is a strong ID for a command, wrapping a string to prevent mixing with other strings.
        explicit CommandId(std::string v) : value(std::move(v)) {}; //constructor that takes a string and initializes the value member.

    };

    // Lifecycle of a command as seen by the dashboard.
    enum class CommandType
    {
        StartAcquisition,
        StopAcquisition,
        Applyconfig,
        ResetDevice,// dangerous by definition
        ShutdownDevice,// dangerous by definition
        Custom 
        //add more commands as neededd 

                    // For future extensibility, allows commands not predefined in the enum.
                    // Note: Custom commands can be identified by a specific CommandType and additional metadata in the payload.
                    //add more command types as needed, but keep in mind the stability of this enum since adapters will depend on it.
    };
    
    enum class CommandStatus
        {
            Pending,         // created, not sent yet
            Sent,            // passed to gateway/transport
            Acked,           // device confirmed success
            Nacked,          // device rejected/failed
            Timeout,         // no response within SLA
            RejectedByCore   // blocked by safety/rules before sending
        };

        // Domain rule: dangerous commands are determined by type (not by user flag).
        inline bool is_dangerous(CommandType type)noexcept
        {
            return (type == CommandType::ResetDevice || type == CommandType::ShutdownDevice);
        }

    struct DeviceCommand
    {
        CommandId id;
        DeviceId Target;
        CommandType type{CommandType::Custom}; // default to Custom for flexibility
        CommandStatus status{CommandStatus::Pending}; // default to Pending

        Timestamp requestedAt{};
        std::string payload;

        //Minimal constructor to keep call sites clean
        //Note:requestedAt is stamped at creation time (domain-level timestamp).
        
        DeviceCommand(CommandId cid,
                    DeviceId dev,
                    CommandType t,
                    std::string p)
            : id(std::move(cid))
            , Target(std::move(dev))
            , type(t)
            , requestedAt(std::chrono::system_clock::now())
            , payload(std::move(p))
        {}
    };



}
