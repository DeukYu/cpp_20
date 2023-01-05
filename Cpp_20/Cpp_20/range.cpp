// Range
#include <iostream>

using namespace std;

#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

template<std::ranges::input_range Range>
requires std::ranges::view<Range>
class ContainerView : public std::ranges::view_interface<ContainerView<Range>>
{
public:
		ContainerView() = default;

		constexpr ContainerView(Range r) : _range(std::move(r)), _begin(std::begin(r)), _end(std::end(r))
		{

		}
		constexpr auto begin() const { return _begin; }
		constexpr auto end() const { return _end; }
private:
	Range _range;
	std::ranges::iterator_t<Range> _begin;
	std::ranges::iterator_t<Range> _end;
};

template<typename Range>
ContainerView(Range&& range)->ContainerView<std::ranges::views::all_t<Range>>;

int main()
{
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 ,7 ,8,9,10 };

	vector<int> v2;
	// 짝수 추출
	for (int n : v1)
	{
		if (n % 2 == 0) v2.emplace_back(n);
	}

	// 2를 곱한다.
	for (int& n : v2)
		n = n * 2;

	auto results = v1
		| std::views::filter([](int n) {return n % 2 == 0;	})
		| std::views::transform([](int n) {return n * 2; });

	/*for (auto n : results)
		cout << n << " ";*/

	// Range : Range란 순회할 수 있는 아이템 그룹 (ex. STL Container)
	// View : Range에 대해서 적응할 수 있는 연산

	auto results2 = v1
		| std::views::filter([](int n) {return n % 2 == 0;	})
		| std::views::transform([](int n) {return n * 2; })
		| std::views::take(3);
	for (auto n : results2)
		cout << n << " ";
	
	struct Knight
	{
		std::string name;
		int			id;
	};

	vector< Knight> knights =
	{
		{"C", 1},
		{"B", 2},
		{"D", 3},
		{"A", 4},
	};

	std::ranges::sort(knights, {}, & Knight::name);
	std::ranges::sort(knights, std::ranges::greater(), &Knight::name);
	std::ranges::sort(knights, {}, & Knight::id);
	std::ranges::sort(knights, std::ranges::greater(), & Knight::id);
	
	map<string, int> m =
	{
		{"C", 1},
		{"B", 2},
		{"D", 3},
		{"A", 4},
	};

	for (const auto& name : std::views::keys(m) | std::views::reverse)
		cout << name << endl;

	auto isPrime = [](int num)
	{
		if (num <= 1)
			return false;
		for (int n = 2; n * n <= num; n++)
			if (num % n == 0)
				return false;
		return true;
	};
	// 0 ~ 100 사이의 숫자중 소수인 5개 숫자를 추출
	std::vector<int> v3;

	for (int n : std::views::iota(0, 100) | std::views::filter(isPrime) | std::views::take(5))
		v3.emplace_back(n);

	// 커스텀 뷰 ( std::ranges::view_interface)
	std::vector<int> myVec{ 1, 2, 3, 4, 5 };
	auto myView = ContainerView(myVec);

	for (auto n : myView)
	{
		cout << n << endl;
	}

	return 0;
}