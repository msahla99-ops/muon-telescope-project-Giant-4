#include "RunAction.hh"
#include "G4Run.hh"
#include <fstream>

RunAction::RunAction() {}
RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {
    std::ofstream outFile("output.txt");
    outFile << "Edep_S1(MeV)\tEdep_S2(MeV)\tEdep_S3(MeV)\tEdep_S4(MeV)\n";
    outFile.close();
    G4cout << "Run started. Output will be written to output.txt" << G4endl;
}

void RunAction::EndOfRunAction(const G4Run* run) {
    G4int nEvents = run->GetNumberOfEvent();
    G4cout << "\n=== Run Complete ===" << G4endl;
    G4cout << "Total events simulated: " << nEvents << G4endl;
    G4cout << "Coincidence events written to output.txt" << G4endl;
}
