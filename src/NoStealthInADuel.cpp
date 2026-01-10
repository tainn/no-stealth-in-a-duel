#include "bzfsAPI.h"

class NoStealthInADuel : public bz_Plugin {
public:
  const char *Name() override;

  void Init(const char *config) override;

  void Cleanup() override;

  void Event(bz_EventData *eventData) override;
};

BZ_PLUGIN(NoStealthInADuel)

const char *NoStealthInADuel::Name() {
  return "NoStealthInADuel 0.1.0";
}

void NoStealthInADuel::Init(const char *config) {
  Register(bz_eFlagGrabbedEvent);
}

void NoStealthInADuel::Cleanup() {
  Flush();
}

void NoStealthInADuel::Event(bz_EventData *eventData) {
  if (eventData->eventType != bz_eFlagGrabbedEvent) {
    return;
  }

  const auto *data = dynamic_cast<bz_FlagGrabbedEventData_V1 *>(eventData);

  if (strcmp(data->flagType, "ST") != 0) {
    return;
  }

  if (bz_getPlayerCount() > 2) {
    return;
  }

  bz_removePlayerFlag(data->playerID);
  bz_sendTextMessagef(BZ_SERVER, data->playerID, "No Stealth in a duel!");
}
