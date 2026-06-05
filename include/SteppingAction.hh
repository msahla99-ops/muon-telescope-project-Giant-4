#ifndef SteppingAction_h
#define SteppingAction_h
#include "G4UserSteppingAction.hh"
#include "G4Types.hh"
#include <vector>
class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction();
    ~SteppingAction();
    void UserSteppingAction(const G4Step*) override;
    void Reset();
    const std::vector<G4double>& GetEdepPanel() const { return fEdepPanel; }
private:
    std::vector<G4double> fEdepPanel;
};
#endif
