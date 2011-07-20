class MultinomialPosterior {
  MatrixBackedTopicCounts topics;
public:
  MultinomialPosterior(const int K_) : topics(K_) {
  }

  virtual double evaluate(const Position& position, const int topic) const {
    position.getDocument()
  }
};
