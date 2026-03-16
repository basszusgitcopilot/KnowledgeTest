#pragma once

#include <functional>
#include <string>

#include "KnowledgeTestDialog.h"

namespace com::prog::knowledgetest {
class KnowledgeTestDialogRunner {
  public:
    struct KnowledgeTestDialogRunnerStatistic {
        int32_t numOfTestItems = 0;
        int32_t numOfRemainingTestItems = 0;
        int32_t numOfTries = 0;
        int32_t numOfCorrectAnswers = 0;
    };
    enum class KnowledgeTestDialogStatus{
      UNINITIALIZED = 0,
      STARTED,
      START_TURN,
      END_TURN,
      ENDED,
    };
    struct KnowledgeTestDialogRunnerConfiguration {
        bool repeatUntilCorrectAnswer = false;
        bool removeOnlyCorrectlyAnsweredItems = true;
        std::function<void(std::string)> showQuestion;
        std::function<std::string()> getAnswer;
        std::function<void(bool, std::string)> reactionToResult;
        std::function<void(KnowledgeTestDialogStatus, KnowledgeTestDialogRunnerStatistic)> useStatistics;
    };

    KnowledgeTestDialogRunner(KnowledgeTestDialogRunnerConfiguration _config);
    auto runKnowledgeTestDialog(std::shared_ptr<KnowledgeTestDialog> testDialog) const -> void;

  private:
    KnowledgeTestDialogRunnerConfiguration config;
};
} // namespace com::prog::latin::tester