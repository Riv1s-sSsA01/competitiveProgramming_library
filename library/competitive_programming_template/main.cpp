#include <iostream>
#include <string>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits>
#include <optional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

namespace sss
{
	namespace io
	{
		auto& outStream = std::cout;

		constexpr auto* const SPACE		= " ";
		constexpr auto* const NEW_LINE	= "\n";

		std::string  TRUE_TEXT = "Yes";
		std::string FALSE_TEXT = "No";

		template<class T>
		void OutputData(const T& value)
		{
			outStream << value;
		}

		void OutputData(const bool is)
		{
			outStream << (is ? TRUE_TEXT : FALSE_TEXT);
		}

		template<class T>
		void OutputLine(const T& value)
		{
			OutputData(value);
			OutputData(NEW_LINE);
		}

		template<class T>
		void OutputLine(const std::vector<T>& collection, const bool isReverse)
		{
			if (collection.empty()) {
				return;
			}

			OutputData(isReverse ? collection.back() : collection.front());

			if (isReverse) {
				std::for_each(
					std::next(std::crbegin(collection)),
					std::crend(collection),
					[&](const auto& value)
					{
						OutputData(SPACE);
						OutputData(value);
					}
				);
			}
			else {
				std::for_each(
					std::next(std::cbegin(collection)),
					std::cend(collection),
					[&](const auto& value)
					{
						OutputData(SPACE);
						OutputData(value);
					}
				);
			}

			OutputData(NEW_LINE);
		}

		template<class T>
		void OutputLine(const std::vector<T>& collection)
		{
			OutputLine(collection, false);
		}

		template<class T>
		void OutputLineReverse(const std::vector<T>& collection)
		{
			OutputLine(collection, true);
		}

		// 可変引数テンプレート
		// https://cpprefjp.github.io/lang/cpp11/variadic_templates.html
		void Output() {}

		template<class Head, class... Tail>
		void Output(const Head& head, const Tail&... tail)
		{
			OutputLine(head);
			Output(tail...);
		}

	} // namespace io

} // namespace sss

class Solver
{
public:
	static void Run()
	{
		InputData input{};
		Input(input);

		Solution solution{};
		Solve(input, solution);

		Output(solution);
	}

private:
	struct InputData
	{
		// mock
		int mock;
		std::vector<int> mocks;
	};
	struct Solution
	{
		// mock
		int		mock;
		bool	isMock;
		std::vector<size_t> mocks;
	};

	static void Input(InputData& input)
	{
		// mock
		std::cin >> input.mock;
		input.mocks.resize(input.mock);

		std::for_each(
			std::begin(input.mocks), std::end(input.mocks),
			[](auto& value)
			{
				std::cin >> value;
			}
		);
	}
	static void Output(const Solution& solution)
	{
		// mock
		sss::io::Output(solution.mock, solution.isMock, solution.mocks);
	}

	static void Solve(InputData& input, Solution& solution)
	{
	}
};

int main()
{
	Solver::Run();
}
