// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"  // This line is for the Simulink code
#include <frc/SmartDashboard/smartdashboard.h>  // This line is for the Smart Dashboard to Simulink input port
#include <networktables/NetworkTable.h>         // This line is for the Smart Dashboard to Simulink input port
#include <networktables/NetworkTableInstance.h> // This line is for the Smart Dashboard to Simulink input port
#include "include/SimulinkSmartDashboard.h"     // This line is to support tunable parameters from Simulink

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

private:
  void PreStep();
  void PostStep();
  nt::NetworkTableEntry Entry;
  SimulinkSmartDashboard m_TunableSmartDashboard;   // This line is to support tunable parameters from Simulink
};