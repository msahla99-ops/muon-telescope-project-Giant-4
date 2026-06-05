#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction() : fEdepPanel(4, 0.0) {}

SteppingAction::~SteppingAction() {}

void SteppingAction::Reset() {
    for(auto& e : fEdepPanel) e = 0.0;
}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    G4double edep = step->GetTotalEnergyDeposit();
    if(edep <= 0) return;

    G4String volName = step->GetPreStepPoint()
                           ->GetTouchableHandle()
                           ->GetVolume()
                           ->GetLogicalVolume()
                           ->GetName();

    if(volName == "S1") fEdepPanel[0] += edep;
    else if(volName == "S2") fEdepPanel[1] += edep;
    else if(volName == "S3") fEdepPanel[2] += edep;
    else if(volName == "S4") fEdepPanel[3] += edep;
}
