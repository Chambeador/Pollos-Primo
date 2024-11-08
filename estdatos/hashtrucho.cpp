random_device rd;
mt19937_64 gen(rd());
map<ull, ull> mapping;
set<ull> usados = { 0 };

for (auto &c : v) {
    ull random;
    if (!mapping.count(c)) {
        do { random = gen(); } while (usados.count(random));
        usados.insert(random);
        mapping[c] = random;
    } else {
        random = mapping[c];
    }
    c = random;
}

//buscar los macros para esto