class Posterior {
public:
  virtual double evaluate(const Position& position, const int topic) const = 0;
  virtual void update(const Position& position, const int topic, const int count) = 0;
};
