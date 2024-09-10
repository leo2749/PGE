using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Threading;


//static void accessControlLoop()

namespace CalculadoraApp
{
    enum AccessEvent { SUMA, RESTA, MULTIPLICACION, DIVISION };

    class Program
    {

        private Dictionary<AccessEvent, Func<double, double, double>> operaciones;

        public Program()
        {

            operaciones = new Dictionary<AccessEvent, Func<double, double, double>>
            {
                { AccessEvent.SUMA, Sumar },
                { AccessEvent.RESTA, Restar },
                { AccessEvent.MULTIPLICACION, Multiplicar },
                { AccessEvent.DIVISION, Dividir }
            };

        }
        static void Main(string[] args)
        {
            Program program = new Program();
            bool continuar = true;
            double resultado = 0;

            while (continuar)
            {
                try
                {
                    Console.WriteLine("Selecciona una operación:");
                    Console.WriteLine("1. Suma");
                    Console.WriteLine("2. Resta");
                    Console.WriteLine("3. Multiplicación");
                    Console.WriteLine("4. División");
                    Console.WriteLine("5. Resetear");
                    Console.WriteLine("6. Salir");
                    Console.Write("Opción: ");
                    string opcion = Console.ReadLine();

                    if (opcion == "6")
                    {
                        continuar = false;
                        continue;
                    }


                   if(opcion != "5")
                    {
                        Console.Write("Ingresa el primer número: ");
                        string input1 = Console.ReadLine();
                        ValidarEntrada(input1);
                        double numero1 = double.Parse(input1);
                        AccessEvent evento = opcion switch
                        {
                            "1" => AccessEvent.SUMA,
                            "2" => AccessEvent.RESTA,
                            "3" => AccessEvent.MULTIPLICACION,
                            "4" => AccessEvent.DIVISION,
                            _ => throw new InvalidOperationException("Operación no válida."),
                        };

                        // Invocamos la operación usando el diccionario
                        double r = program.operaciones[evento].Invoke(resultado, numero1);
                        resultado = r;

                        Console.WriteLine($"El resultado es: {r}");

                    }else {
                        Console.WriteLine("Reseteado.");
                        resultado = 0; }
                   
                }
                catch (FormatException ex)
                {
                    Console.WriteLine("Error: Ingresaste un valor que no es numérico.");
                    Console.WriteLine("Detalles: " + ex.Message);
                }
                catch (ArgumentNullException ex)
                {
                    Console.WriteLine("Error: El valor ingresado es nulo.");
                    Console.WriteLine("Detalles: " + ex.Message);
                }
                catch (ArgumentException ex)
                {
                    Console.WriteLine("Error: " + ex.Message);
                }
                catch (DivideByZeroException ex)
                {
                    Console.WriteLine("Error: No se puede dividir por cero.");
                    Console.WriteLine("Detalles: " + ex.Message);
                }
                catch (InvalidOperationException ex)
                {
                    Console.WriteLine("Error: Operación no válida.");
                    Console.WriteLine("Detalles: " + ex.Message);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Ocurrió un error inesperado: " + ex.Message);
                }
                finally
                {
                    Console.WriteLine("Operación finalizada.");
                }

                Console.WriteLine();
            }
        }

        static void ValidarEntrada(string entrada)
        {
            if (string.IsNullOrEmpty(entrada))
            {
                throw new ArgumentException("La entrada no puede estar vacía.");
            }
        }

        // Métodos que manejan las operaciones
        static double Sumar(double a, double b) => a + b;
        static double Restar(double a, double b) => a - b;
        static double Multiplicar(double a, double b) => a * b;
        static double Dividir(double a, double b)
        {
            if (b == 0)
            {
                throw new DivideByZeroException("El divisor no puede ser cero.");
            }
            return a / b;
        }
    }

}