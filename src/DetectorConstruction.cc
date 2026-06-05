#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
DetectorConstruction::DetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {}
G4VPhysicalVolume* DetectorConstruction::Construct() {
G4NistManager* nist = G4NistManager::Instance();
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* plastic = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    G4double panelX = 25.0*cm;
    G4double panelY = 1.28*cm;
    G4double panelZ = 2.5*cm;
    G4Box* worldBox = new G4Box("World", 40*cm, 40*cm, 40*cm);
    G4LogicalVolume* worldLV = new G4LogicalVolume(worldBox, air, "World");
    G4VPhysicalVolume* worldPV = new G4PVPlacement(
        0, G4ThreeVector(), worldLV, "World", 0, false, 0);
        G4double gap = 0.1*mm;
    G4double y1 =  1.5*(panelY + gap);
    G4double y2 =  0.5*(panelY + gap);
    G4double y3 = -0.5*(panelY + gap);
    G4double y4 = -1.5*(panelY + gap);
    G4Box* panelBox = new G4Box("Panel", panelX/2, panelY/2, panelZ/2);

    G4VisAttributes* s1Vis = new G4VisAttributes(G4Colour(0.0, 0.5, 1.0));
    G4VisAttributes* s2Vis = new G4VisAttributes(G4Colour(0.0, 1.0, 0.5));
    G4VisAttributes* s3Vis = new G4VisAttributes(G4Colour(0.8, 0.8, 0.8));
    G4VisAttributes* s4Vis = new G4VisAttributes(G4Colour(1.0, 0.3, 0.0));
    G4LogicalVolume* s1LV = new G4LogicalVolume(panelBox, plastic, "S1");
    s1LV->SetVisAttributes(s1Vis);
    new G4PVPlacement(0, G4ThreeVector(0, y1, 0), s1LV, "S1", worldLV, false, 0);
    G4LogicalVolume* s2LV = new G4LogicalVolume(panelBox, plastic, "S2");
    s2LV->SetVisAttributes(s2Vis);
    new G4PVPlacement(0, G4ThreeVector(0, y2, 0), s2LV, "S2", worldLV, false, 1);

    G4LogicalVolume* s3LV = new G4LogicalVolume(panelBox, plastic, "S3");
    s3LV->SetVisAttributes(s3Vis);
    new G4PVPlacement(0, G4ThreeVector(0, y3, 0), s3LV, "S3", worldLV, false, 2);

    G4LogicalVolume* s4LV = new G4LogicalVolume(panelBox, plastic, "S4");
    s4LV->SetVisAttributes(s4Vis);
    new G4PVPlacement(0, G4ThreeVector(0, y4, 0), s4LV, "S4", worldLV, false, 3);
    return worldPV;
}

