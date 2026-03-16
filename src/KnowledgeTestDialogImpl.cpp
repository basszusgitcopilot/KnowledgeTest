#include "KnowledgeTestDialogImpl.h"

namespace com::prog::knowledgetest {
auto KnowledgeTestDialogImpl::addTestItems(std::vector<std::shared_ptr<KnowledgeTestItem>> _testItems) -> void {
    testItems.insert(testItems.end(), _testItems.begin(), _testItems.end());
}
auto KnowledgeTestDialogImpl::getKnowledgeTestItems() const -> std::vector<std::shared_ptr<KnowledgeTestItem>> { return testItems; }
} // namespace com::prog::knowledgetest