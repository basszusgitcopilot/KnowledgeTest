#pragma once

#include "KnowledgeTestItem.h"

#include <memory>
#include <vector>

namespace com::prog::knowledgetest {

class KnowledgeTestDialog {
  public:
    virtual ~KnowledgeTestDialog() = default;
    virtual auto getKnowledgeTestItems() const -> std::vector<std::shared_ptr<KnowledgeTestItem>> = 0;
};

} // namespace com::prog::latin::tester