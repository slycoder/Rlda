class MatrixBackedTopicCounts : public TopicCounts {
  Rcpp::Matrix<INTSXP> topic_word_counts_;
  Rcpp::Vector<INTSXP> topic_counts_;
public:
  virtual int getTopicWordCount(const int topic, const int word) const {
    return topic_word_counts_(topic, word);
  }

  virtual int getTopicCount(const int topic) const {
    return topic_counts_[topic];
  }

  virtual void update(const int topic, const int word, const int count) {
    
  }
};
