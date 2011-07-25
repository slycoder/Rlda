#include <vector>
#include "Document.cpp"

class Corpus {
private:
  std::vector<Document> documents_;

public:
  unsigned int getSize() const { 
    return documents_.size();
  }

  const Document& getDocument(const unsigned int index) const {
    return documents_[index];
  }
};
