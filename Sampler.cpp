#include <vector>

class Sampler {
  int K_;
  std::vector<Posterior> posteriors_; 
  std::vector<double> probabilities_;
public:
  Sampler(const int K) : K_(K), probabilities_(K) {
  }

  void addPosterior(Posterior& posterior) {
    posteriors_.push_back(posterior);
  }

  int sampleVariable(const Position& position) const {
    double psum = 0.0;
    for (int kk = 0; kk < K_; ++kk) {
      probabilities_[kk] = 1.0;
      for (std::vector<Posterior> pp = posteriors_.begin();
           pp != posteriors_.end(); ++pp) {
        probabilities_[kk] *= pp->evaluate(position, kk);
      }
      psum += probabilities_[kk];
    }


    double r = runif();
    for (int kk = 0; kk < K_; ++k) {
      if (r < probabilities_[kk] / psum) {
        return kk;
      }
      r -= probabilities_[kk] / psum;
    }
    return -1;
  }

  void iterate() {
    for (Position pos = corpus.start();
         pos; ++pos) {
      for (std::vector<Posterior> pp = posteriors_.begin();
           pp != posteriors_.end(); ++pp) {
        pp->update(position, kk, -1);
      }
      sampleVariable(pos);
      for (std::vector<Posterior> pp = posteriors_.begin();
           pp != posteriors_.end(); ++pp) {
        pp->update(position, kk, +1);
      }
    }
  }
};
