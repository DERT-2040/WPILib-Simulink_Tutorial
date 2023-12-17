// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
#include "include/SimulinkSmartDashboard.h"
 
void SimulinkSmartDashboard::InitTunableSmartDashboard() {
    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
    auto NTtable = NTinst.GetTable("Simulink_Tunable_Params");
 
    __Frequency__Entry = NTtable->GetEntry("Frequency");
    NTinst.AddListener(__Frequency__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Frequency = event.GetValueEventData()->value.GetDouble();});
    __Frequency__Entry.SetDouble(0.25);
 
    __Offset__Entry = NTtable->GetEntry("Offset");
    NTinst.AddListener(__Offset__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Offset = event.GetValueEventData()->value.GetDouble();});
    __Offset__Entry.SetDouble(0);
}
