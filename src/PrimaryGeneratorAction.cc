#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = new G4ParticleGun(1);

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* muon = particleTable->FindParticle("mu-");

    fParticleGun->SetParticleDefinition(muon);
    fParticleGun->SetParticlePosition(G4ThreeVector(0, 15*cm, 0));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0, -1, 0));
    fParticleGun->SetParticleEnergy(4*GeV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    fParticleGun->GeneratePrimaryVertex(event);
}
