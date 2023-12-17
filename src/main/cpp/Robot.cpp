// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "include/Robot.h"

void Robot::RobotInit() {Code_Gen_Model_U.Game_State = 0;
  Code_Gen_Model_initialize(); //code gen model init 

  // This block of code is just to get a Smart Dashboard parameter passed to a Simulink input port
  // Normally the Simulink input ports would be connected to Human Input Devices or Sensors
  nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
  auto NTtable = NTinst.GetTable("Simulink Input Ports");  // section in Network tables
  Entry = NTtable->GetEntry("Simulink Input Port");        // parameter name in Network tables
  NTinst.AddListener(Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Code_Gen_Model_U.Smart_Dashboard_input = event.GetValueEventData()->value.GetDouble();});    // Input ports are prepended with "Code_Gen_Model_U."
  Entry.SetDouble(1);  // Initial value

  // This line is to support tunable parameters from Simulink
  m_TunableSmartDashboard.InitTunableSmartDashboard();
}
void Robot::RobotPeriodic() {
  PreStep(); //Robot wide PreStep
  Code_Gen_Model_step(); //Step the model
  PostStep(); //Robot wide PostStep
}

void Robot::AutonomousInit() {Code_Gen_Model_U.Game_State = 1;}    // Input ports are prepended with "Code_Gen_Model_U."
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {Code_Gen_Model_U.Game_State = 2;}    // Input ports are prepended with "Code_Gen_Model_U."
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {Code_Gen_Model_U.Game_State = 0;}    // Input ports are prepended with "Code_Gen_Model_U."
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {Code_Gen_Model_U.Game_State = 3;}    // Input ports are prepended with "Code_Gen_Model_U."
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

void Robot::PreStep() {}
void Robot::PostStep() {
  // This line sends the Simulink output port data to Smart Dashboard
  // Output ports are prepended with "Code_Gen_Model_Y."
  // In this case it is only going to the dashboard, but normally it would be going to drive a motor output
  frc::SmartDashboard::PutNumber("Simulink Output Port",Code_Gen_Model_Y.Smart_Dashboard_output);

  // This line sends the Simulink test point data to Smart Dashboard
  // Test points are prepended with "Code_Gen_Model_B."
  frc::SmartDashboard::PutNumber("Sine Wave Raw",Code_Gen_Model_B.sine_wave_raw);
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
