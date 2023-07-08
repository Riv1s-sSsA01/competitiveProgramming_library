#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>
#include <optional>
#include <vector>
#include <set>
#include <numeric>
#include <limits>

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
		void OutputLine(const std::vector<T>& collection)
		{
			if (collection.empty()) {
				return;
			}

			OutputData(collection.front());

			std::for_each(
				std::next(std::cbegin(collection)), std::cend(collection),
				[&](const auto& value)
				{
					OutputData(SPACE);
					OutputData(value);
				}
			);

			OutputData(NEW_LINE);
		}

		// �ψ����e���v���[�g
		// https://cpprefjp.github.io/lang/cpp11/variadic_templates.html
		//template<class Head, class... Tail>
		//void Output(const std::vector<Head>& head, const std::vector<Tail>&... tail)
		//{
		//	OutputLine(head);
		//	Output(tail...);
		//}

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
	}

	static void Solve(InputData& input, Solution& solution)
	{
	}

	static void Output(const Solution& solution)
	{
		// mock
		sss::io::OutputLine(solution.mock);
		sss::io::OutputLine(solution.isMock);
		sss::io::OutputLine(solution.mocks);
	}
};

int main()
{
	Solver::Run();
}