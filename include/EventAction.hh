#ifndef EventAction_h
#define EventAction_h
#include "G4UserEventAction.hh"
#include "G4Types.hh"
class SteppingAction;
class EventAction : public G4UserEventAction {
public:
    EventAction(SteppingAction*);
    ~EventAction();
    void BeginOfEventAction(const G4Event*) override;
    void EndOfEventAction(const G4Event*) override;
private:
    SteppingAction* fSteppingAction;
    G4int fCoincidenceCount;
};
#endif
