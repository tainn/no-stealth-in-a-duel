#include "bzfsAPI.h"

class NoStealthInADuel : public bz_Plugin {
public:
  const char *Name() override;

  void Init(const char *config) override;

  void Cleanup() override;

  void Event(bz_EventData *eventData) override;

private:
  std::vector<std::string> bannedFlags;
};

BZ_PLUGIN(NoStealthInADuel)

const char *NoStealthInADuel::Name() {
  return "NoStealthInADuel 0.2.0";
}

void NoStealthInADuel::Init(const char *config) {
  Register(bz_eFlagGrabbedEvent);

  if (!config || strlen(config) == 0) {
    bannedFlags.emplace_back("ST");
    return;
  }

  bz_APIStringList *list = bz_newStringList();
  list->tokenize(config, ":");

  for (unsigned int i = 0; i < list->size(); i++) {
    const char *trimmedFlag = bz_trim(list->get(i).c_str());

    if (trimmedFlag && strlen(trimmedFlag) > 0) {
      bannedFlags.emplace_back(trimmedFlag);
    }
  }

  bz_deleteStringList(list);
}

void NoStealthInADuel::Cleanup() {
  Flush();
}

void NoStealthInADuel::Event(bz_EventData *eventData) {
  if (eventData->eventType != bz_eFlagGrabbedEvent) {
    return;
  }

  const auto *data = dynamic_cast<bz_FlagGrabbedEventData_V1 *>(eventData);

  bool isBanned = false;

  for (const auto &flag: bannedFlags) {
    if (flag == data->flagType) {
      isBanned = true;
      break;
    }
  }

  if (!isBanned) {
    return;
  }

  if (bz_getPlayerCount() > 2) {
    return;
  }

  bz_removePlayerFlag(data->playerID);
  const bz_ApiString flagNameObj = bz_getFlagName(data->flagID);
  bz_sendTextMessagef(BZ_SERVER, data->playerID, "No %s in a duel!", flagNameObj.c_str());
}
