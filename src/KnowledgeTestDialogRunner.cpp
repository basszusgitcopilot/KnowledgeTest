#include "KnowledgeTestDialogRunner.h"
#include <random>

namespace com::prog::knowledgetest {

KnowledgeTestDialogRunner::KnowledgeTestDialogRunner(KnowledgeTestDialogRunnerConfiguration _config) : config{std::move(_config)} {}

auto KnowledgeTestDialogRunner::runKnowledgeTestDialog(std::shared_ptr<KnowledgeTestDialog> testDialog) const -> void {
    KnowledgeTestDialogRunnerStatistic statistics;
    config.useStatistics(KnowledgeTestDialogStatus::STARTED, statistics);
    auto testItems = testDialog->getKnowledgeTestItems();
    statistics.numOfTestItems = testItems.size();
    statistics.numOfRemainingTestItems = testItems.size();
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    while (!testItems.empty()) {
        config.useStatistics(KnowledgeTestDialogStatus::START_TURN, statistics);
        std::uniform_int_distribution<int> uniform_dist(0, testItems.size() - 1);
        auto itemIndex = uniform_dist(randomEngine);
        auto testItem = testItems.at(itemIndex);
        bool result = false;
        bool firstTry = true;
        while (!result && (firstTry || config.repeatUntilCorrectAnswer)) {
            statistics.numOfTries++;
            firstTry = false;
            auto question = testItem->getQuestion();
            config.showQuestion(question);
            auto answer = config.getAnswer();
            auto checkAnswerResult = testItem->checkAnswer(answer);
            result = checkAnswerResult.ok;

            config.reactionToResult(result, checkAnswerResult.rightAnswer);

            if (result) {
                statistics.numOfCorrectAnswers++;
            }
        }
        if (result || !config.removeOnlyCorrectlyAnsweredItems) {
            testItems.erase(testItems.begin() + itemIndex);
        }
        statistics.numOfRemainingTestItems = testItems.size();
        config.useStatistics(KnowledgeTestDialogStatus::END_TURN, statistics);
    }
    config.useStatistics(KnowledgeTestDialogStatus::ENDED, statistics);
}
} // namespace com::prog::knowledgetest