class TopicCounts {
public:
  virtual int getTopicWordCount(const int topic, const int word) const = 0;
  virtual int getTopicCount(const int topic) const = 0;
  virtual void update(const int topic, const int word, const int count) = 0;
};
