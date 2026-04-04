#pragma once

#include <string>
#include <vector>

namespace com::prog::knowledgetest {
class KnowledgeTestItem {
  public:
    struct CheckAnswerResult{
      bool ok;
      std::string rightAnswer;
    };

    virtual ~KnowledgeTestItem() = default;
    virtual auto getQuestion() const -> std::string = 0;
    virtual auto getRightAnswer() const -> std::string = 0;
    virtual auto checkAnswer(const std::string &answer) -> CheckAnswerResult = 0;
};
} // namespace com::prog::latin::tester