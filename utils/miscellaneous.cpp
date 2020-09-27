// Hash for unordered_set

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const  {
        return v.first*31+v.second;
    }
};

unordered_set<pair<int,int>, pair_hash> s;

// Modulus of positive / negative numbers

int mod(int a, int b) { return (a % b + b) % b; }