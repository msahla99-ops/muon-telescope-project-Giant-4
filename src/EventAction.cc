#include "EventAction.hh"
#include "SteppingAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include <fstream>

EventAction::EventAction(SteppingAction* steppingAction)
: fSteppingAction(steppingAction), fCoincidenceCount(0) {}

EventAction::~EventAction() {}

void EventAction::BeginOfEventAction(const G4Event*) {
    fSteppingAction->Reset();
}

void EventAction::EndOfEventAction(const G4Event*) {
    const auto& edep = fSteppingAction->GetEdepPanel();

    G4double eS1 = edep[0]/MeV;
    G4double eS2 = edep[1]/MeV;
    G4double eS3 = edep[2]/MeV;
    G4double eS4 = edep[3]/MeV;

    if(eS1 > 0.5 && eS2 > 0.5 && eS4 > 0.5) {
        fCoincidenceCount++;
        std::ofstream outFile("output.txt", std::ios::app);
        outFile << eS1 << "\t" << eS2 << "\t" << eS3 << "\t" << eS4 << "\n";
        outFile.close();
    }
}
