import unittest
from conjMaxEj3 import subconjuntoMaximo
from corteEj8 import corte
from terrenoEj9 import terreno
from soporteCajaEj10 import pilaMasGrande
from posiblesDadosEj12 import sumaDadosIndistinguibles
from parejasEj13 import maximoParejas

# class TestConjMax(unittest.TestCase):
#     def test1(self):
#         self.k = 3
#         self.M = [[0, 10, 10, 1],
#                   [10, 0, 5, 2],
#                   [10, 5, 0, 1],
#                   [1, 2, 1, 0]]
#         self.cMax = set()
#         subconjuntoMaximo(set(), 0)
#         self.assertSetEqual(self.cMax, {0, 1, 2})


class TestParejas(unittest.TestCase):

    def test_suma(self):
        self.assertEqual(maximoParejas([1, 2, 3, 4], [1, 2, 3, 4]), 4)
        self.assertEqual(maximoParejas([1, 2, 3, 4], [1, 2, 3, 6]), 3)
        self.assertEqual(maximoParejas([1, 2, 3, 4, 8], [1, 2, 3, 6, 7, 9]), 4)
        self.assertEqual(maximoParejas(
            [1, 2, 3, 4, 8], [1, 2, 3, 6, 7, 9, 10]), 4)

    def test_suma2(self):
        self.assertEqual(maximoParejas([1, 2, 3, 4], [1, 2, 3, 4]), 4)
        self.assertEqual(maximoParejas([1, 2, 3, 4], [1, 2, 3, 6]), 3)
        self.assertEqual(maximoParejas([1, 2, 3, 4, 8], [1, 2, 3, 6, 7, 9]), 4)
        self.assertEqual(maximoParejas(
            [1, 2, 3, 4, 8], [1, 2, 3, 6, 7, 9, 10]), 4)

    def test_suma3(self):
        self.assertEqual(maximoParejas([1, 2, 3, 4], [1, 2, 3, 4]), 4)
        self.assertEqual(maximoParejas([1, 2, 3, 4], [1, 2, 3, 6]), 3)
        self.assertEqual(maximoParejas([1, 2, 3, 4, 8], [1, 2, 3, 6, 7, 9]), 4)
        self.assertEqual(maximoParejas(
            [1, 2, 3, 4, 8], [1, 2, 3, 6, 7, 9, 10]), 4)
        
        
unittest.main()