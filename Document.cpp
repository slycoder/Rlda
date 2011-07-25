/**
 * Abstract interface for documents.
 */
class DocumentBase {
public:
  virtual unsigned int getLength() const = 0;
};


template<typename T>
class Document : public DocumentBase {
public:
  virtual T getData() const = 0;
}


