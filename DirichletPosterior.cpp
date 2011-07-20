class DirichletPosterior {
  Rcpp::Matrix<INTSXP> document_topic_counts_;
  double alpha_;
public:
#error initialize matrix objects
  DirichletPosterior(const int K, double alpha) : topics(K), alpha_(alpha_) {
  }

  virtual double evaluate(const int topic, const Position& position) const {
    return document_topic_counts_(topic, position.getDocument()) + alpha;
  }

  virtual void update(const int topic, const Position& position, const int count) {
    document_topic_counts_(topic, position.getDocument()) += count;
  }
};
