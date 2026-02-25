# Embedded Device Dashboard

> A professional desktop application for real-time monitoring and control of embedded devices (STM32/ESP32) via USB serial communication.

---

## 🎯 Project Vision

### The Problem

During hardware development and production testing of custom PCBs, I needed a fast, reliable way to:
- Monitor sensor integration in real-time
- Debug communication issues with embedded devices
- Quickly test different configurations without reflashing firmware
- Have a professional tool for production device monitoring

Existing solutions were either too heavyweight, lacked flexibility, or didn't integrate well with my workflow.

### The Solution

A **portfolio-grade, production-quality** desktop application that bridges embedded systems with modern C++ software engineering. Built to solve a real problem while showcasing professional development practices.

This project demonstrates:
- **Clean Architecture** with strict layer separation
- **Modern C++20** practices (RAII, smart pointers, value semantics)
- **Cross-platform** desktop development with Qt6
- **Real-time telemetry** visualization and device control
- **Professional testing** and build infrastructure

### Why C++?

This project is an opportunity to:
- Strengthen C++ skills for desktop tooling
- Apply embedded systems knowledge to software architecture
- Build a standout portfolio project
- Create a genuinely useful tool for hardware development

---

## 🏗️ Architecture

The application follows a **layered architecture** with clear separation of concerns:

```
┌─────────────────────────────────────────────────┐
│                    UI Layer                     │
│  (Qt Widgets, Panels, Charts, User Interface)   │
└────────────────┬────────────────────────────────┘
                 │
┌────────────────▼────────────────────────────────┐
│              Application Layer                  │
│   (Use Cases, Application Services, DTOs)       │
└────────────────┬────────────────────────────────┘
                 │
┌────────────────▼────────────────────────────────┐
│               CORE Layer (Domain)               │
│    (Business Logic, Entities, Value Objects)    │
│          🔴 NO DEPENDENCIES ON QT/INFRA         │
└────────────────┬────────────────────────────────┘
                 │
┌────────────────▼────────────────────────────────┐
│           Infrastructure Layer                  │
│  (QSerialPort, Parsers, Logger, Config, DB)     │
└─────────────────────────────────────────────────┘
```

### Layer Responsibilities

#### 📦 **CORE** (`src/core/`)
- **Purpose**: Business logic and domain model
- **Contains**:
  - Domain entities (`Device`, `TelemetrySample`)
  - Value objects (`DeviceId`, `DeviceInfo`, `SensorReading`)
  - Domain services (`TelemetryService`, `AlarmEngine`)
  - Port interfaces (`IDeviceGateway`, `ILogger`)
- **Rules**:
  - ✅ Pure C++20 (no Qt dependencies)
  - ✅ No I/O operations
  - ✅ Fully testable in isolation
  - ❌ Cannot use `QSerialPort`, `QFile`, etc.

#### 🔌 **INFRASTRUCTURE** (`src/infra/`)
- **Purpose**: Technical implementation details
- **Contains**:
  - Serial communication (`SerialDeviceGateway`)
  - Protocol parsing (`ProtocolParser`)
  - Logging (`FileLogger`)
  - Configuration (`JsonConfigStorage`)
- **Rules**:
  - ✅ Can use Qt classes
  - ✅ Implements CORE interfaces
  - ❌ No business logic

#### 🖥️ **UI** (`src/ui/`)
- **Purpose**: User interface and presentation
- **Contains**:
  - Main window
  - Panels (Connection, Telemetry, Charts, Commands, Logs)
  - ViewModels (optional, for complex state)
- **Rules**:
  - ✅ Uses Qt Widgets
  - ✅ Calls application services
  - ❌ No direct serial port access

#### 🚀 **APP** (`src/app/`)
- **Purpose**: Composition root and dependency injection
- **Contains**:
  - `main.cpp`
  - Dependency wiring
  - Application startup
- **Rules**:
  - ✅ Instantiates all layers
  - ✅ Injects dependencies
  - ❌ Minimal logic

---

## 📡 Communication Protocol

> **Status**: Under definition

The application communicates with embedded devices using a custom binary protocol over USB CDC (Serial).

### Protocol Structure (Draft)

```
┌─────────────────────────────────────────────────────────┐
│ FRAME STRUCTURE                                         │
├─────────────────────────────────────────────────────────┤
│ [SYNC(2B)] [TYPE(1B)] [LEN(2B)] [PAYLOAD(N)] [CRC(2B)] │
└─────────────────────────────────────────────────────────┘

SYNC:    0xAA55 (frame synchronization marker)
TYPE:    Message type identifier
LEN:     Payload length in bytes
PAYLOAD: Message-specific data
CRC:     CRC16-CCITT checksum
```

### Message Types (Preliminary)

**Device → PC:**
- `TELEMETRY_DATA` - Sensor readings
- `DEVICE_INFO` - Firmware version, model, serial number
- `COMMAND_ACK` - Command acknowledged
- `ALARM_EVENT` - Alarm/warning triggered

**PC → Device:**
- `CMD_START_ACQ` - Start data acquisition
- `CMD_STOP_ACQ` - Stop data acquisition
- `CMD_SET_CONFIG` - Update device configuration
- `CMD_GET_INFO` - Request device information

> Full protocol specification will be documented in `docs/protocol.md`

---

## 🛠️ Technical Stack

### Core Technologies
- **Language**: C++20
- **GUI Framework**: Qt 6.x
- **Build System**: CMake 3.20+
- **Testing**: Google Test
- **Version Control**: Git

### Target Platforms
- Windows 10/11
- Linux (Ubuntu 20.04+)
- macOS (Catalina+)

### Embedded Targets
- STM32 microcontrollers (ARM Cortex-M)
- ESP32 (FreeRTOS)

---

## 🏗️ Build Instructions

> Coming soon - CMake setup in progress

---

## 🧪 Testing

> Coming soon - Google Test integration planned

---

## 📚 Domain Model (CORE Layer)

### Key Concepts

#### **Device** (Aggregate Root)
The central entity representing an embedded device. Maintains:
- Identity (`DeviceId`)
- Metadata (`DeviceInfo`)
- Connection state
- Current configuration
- Telemetry window

#### **TelemetrySample**
A snapshot of all sensor readings at a specific timestamp.

#### **SensorReading**
Individual sensor measurement (temperature, voltage, etc.)

#### **DeviceCommand**
Command sent from PC to device (start/stop, configure, etc.)

#### **AlarmEvent**
Notification when sensor values violate configured thresholds

---

## 🎓 Learning Goals

This project is designed to develop expertise in:

1. **Software Architecture**
   - Clean Architecture / Hexagonal Architecture
   - Dependency Inversion Principle
   - Domain-Driven Design concepts

2. **Modern C++**
   - C++20 features
   - RAII and resource management
   - Smart pointers and value semantics
   - Template metaprogramming (where appropriate)

3. **Desktop Development**
   - Qt6 framework
   - Event-driven programming
   - Cross-platform GUI design

4. **Embedded Integration**
   - Serial protocols
   - Binary parsing
   - Real-time data handling

5. **Professional Practices**
   - Unit testing
   - CMake build systems
   - Git workflow
   - Documentation

---

## 📖 Documentation

- `README.md` - This file
- `docs/architecture.md` - Detailed architecture diagrams
- `docs/protocol.md` - Communication protocol specification
- `docs/domain.md` - Domain model documentation
- `docs/build.md` - Build and development guide

---

## 🤝 Contributing

This is a personal portfolio project, but feedback and suggestions are welcome!

---

## 📝 License

> To be determined

---

## 👤 Author

Portfolio project showcasing embedded systems + modern C++ development skills.

---

## 🚀 Roadmap

### Phase 1: Foundation (Current)
- ✅ Architecture design
- 🚧 Protocol definition
- 🚧 CORE domain implementation
- 📋 CMake setup

### Phase 2: Infrastructure
- 📋 Serial communication
- 📋 Protocol parser
- 📋 Logging system
- 📋 Configuration management

### Phase 3: User Interface
- 📋 Main window
- 📋 Connection panel
- 📋 Real-time charts
- 📋 Command interface

### Phase 4: Polish
- 📋 Comprehensive testing
- 📋 Error handling
- 📋 Performance optimization
- 📋 Documentation

### Phase 5: Advanced Features
- 📋 Multi-device support
- 📋 Data recording/playback
- 📋 Custom command scripting
- 📋 Plugin system

---

**Last Updated**: December 2024  
**Status**: Active Development - Foundation Phase