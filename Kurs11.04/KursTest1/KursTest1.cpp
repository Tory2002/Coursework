#include "pch.h"
#include "CppUnitTest.h"
#include "../Kurs11.04/Kurs11.04.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KursTest1
{
	TEST_CLASS(KursTest1)
	{
	
	public:
		//Тест на проверку работы функции f(x):
		TEST_METHOD(TestFunction)
		{
			double x = 4;
			double expected = 128;
			double actual = f(x);
			Assert::AreEqual(expected, actual, 0.0001);
		}
		//Тест на проверку вычисления производной функции df(x, h) :

		TEST_METHOD(TestDerivative)
		{
			double x = 4;
			double h = 0.0001;
			double expected = 240;
			double actual = df(x, h);
			Assert::AreEqual(expected, actual, 0.0001);
		}

		//Тест на проверку работы алгоритма Ньютона с заданными параметрами:

		TEST_METHOD(TestNewton)
		{
			double x = 4;
			double eps = 0.0001;
			double h = 0.0001;
			double expected = 3.28587;
			double actual = newton(x, eps, h);
			Assert::AreEqual(expected, actual, 0.0001);
		}




		
		
	};
}
