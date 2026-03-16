#pragma once

#include "KnowledgeTestDialog.h"

#include <memory>
#include <vector>

namespace com::prog::knowledgetest {

class KnowledgeTestDialogImpl: public KnowledgeTestDialog {
  public:
    auto getKnowledgeTestItems() const -> std::vector<std::shared_ptr<KnowledgeTestItem>> override;
    auto addTestItems(std::vector<std::shared_ptr<KnowledgeTestItem>> _testItems) -> void;

  private:
    std::vector<std::shared_ptr<KnowledgeTestItem>> testItems;
};

} // namespace com::prog::latin::tester