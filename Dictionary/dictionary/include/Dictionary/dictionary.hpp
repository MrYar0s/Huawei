#ifndef DICTIONARY_INCLUDE_DICTIONARY_DICTIONARY_HPP
#define DICTIONARY_INCLUDE_DICTIONARY_DICTIONARY_HPP

#include "../HashTable/hashtable.hpp"

#include <vector>

class Dictionary final : public HashTable<std::string, size_t>
{
public:
	Dictionary() = default;
	explicit Dictionary(size_t thr_num = std::thread::hadrware_concurrency());
	Dictionary(const Dictionary& other) = default;
	Dictionary(Dictionary&& other) noexcept = default;
	~Dictionary() = default;

	Dictionary& operator=(const Dictionary& other) = default;
	Dictionary& operator=(Dictionary&& other) noexcept = default;

	void thr_set(size_t thr_num);
	size_t thr_get() const;

	std::string* candidate(const std::string& word, size_t lev_dist) const;

	size_t calculate_distance(const std::string& word, const std::string& other);

	const size_t LEV_DIST = 1;
	const size_t FREQ_OF_REPLACE = 10;
private:
	std::string* candidate_thr(const std::string& word, size_t lev_dist) const;
	std::vector<std::thread> threads_;
	size_t thr_num;
}

#endif //DICTIONARY_INCLUDE_DICTIONARY_DICTIONARY_HPP