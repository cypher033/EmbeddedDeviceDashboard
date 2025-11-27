# 📘 Project Insights – Embedded Device Dashboard (C++/Qt + USB + Real-Time Telemetry)
## Overview
This project was created to bridge the gap between embedded systems and high-level C++ application development. As embedded engineers grow into more senior or cross-functional roles, it becomes essential to master not only microcontroller firmware but also the desktop tools, visualization applications, and diagnostic interfaces that interact with embedded devices.
The Embedded Device Dashboard is a professional-grade, cross-platform desktop application built with C++17 and Qt 6, designed to communicate with an STM32 microcontroller via USB (CDC/Serial). The application provides real-time telemetry visualization, device state monitoring, interactive charts, and bidirectional command/control capabilities.
This project simulates what many engineering teams build internally for debugging, production testing, data-acquisition, IoT device management, and human–machine interaction.

## Purpose of the Project
This project demonstrates how to design and implement a full end-to-end system that integrates:

-Embedded firmware

-High-performance C++ applications

-Real-time communication

-Modern software architecture

-Professional UI/UX for engineering tools

-It is also meant to showcase my ability to deliver a complete engineering solution—from device protocol design to UI dashboards—using industry-standard patterns and practices.

-In interviews, this project shows that I can operate as a full-stack engineer for embedded systems, covering hardware, firmware, and desktop software with strong architectural reasoning.

## What Problem Does This Solve?

Many embedded devices require:

-Real-time monitoring during development or field testing

-Interactive configuration interfaces

-Data visualization tools

-Diagnostics and logging platforms

-Production-line test applications

-Parameter tuning/calibration tools
### This project solves exactly that problem:
It provides a clean, powerful tool to inspect, control, and understand the behavior of an embedded system.
Companies in IoT, automotive, industry, robotics, medical devices, sensor platforms, and automation routinely build similar tools.
echnical Highlights

## ✔ Modern C++ Development
-C++17/C++20 idioms

-RAII and smart pointers (unique_ptr, shared_ptr)

-STL containers and algorithms

-Zero-cost abstractions

-Strong type safety with enums, variants, optionals

-Clean separation of concerns across modules

## ✔ Qt Framework (Qt 6)
-Cross-platform UI with Qt Widgets or Qt Quick

-Signals/slots event-driven architecture

-QSerialPort for asynchronous USB/CDC communication

-Real-time charting using QtCharts

-Thread-safe updates and worker threads

## ✔ Robust Communication Layer
-Asynchronous USB/Serial protocol

-Custom binary framing with length, message type, and checksum

-Telemetry packets and structured commands

-Error handling, reconnect logic, timeouts

-Incremental parsing (buffered state machine)

## ✔ Core Architecture
-Layered architecture (App / UI / Core / Infrastructure)

-Interfaces and abstractions (IDeviceConnection, ITelemetryParser)

-Strategy, Factory, Observer, and Adapter design patterns

-Domain-driven components (TelemetryData, DeviceState, Commands)

-Strict dependency boundaries to ensure testability and scalability

## ✔ Real-Time Visualizations
-Live sensor readings on charts

-Dynamic data feeds updated from background threads

-Smooth UI updates without blocking the main event loop

## ✔ Logging & Diagnostics
-Structured logging with timestamps

-Log file rotation

-UI log panel for real-time messages

-Error surfaces + user feedback

## Engineering Skills Demonstrated

### Technical Skills

-Advanced C++ application architecture

-Qt desktop development (Widgets/Quick)

-Embedded–desktop integration

-USB/CDC communication

-Real-time data processing

-Multithreaded design

-High-level protocols and low-level framing

-Modern build systems (CMake)

-Cross-platform development

-Testable, maintainable design patterns
