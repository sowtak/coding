using System;

class Program
{
  static void Main() {
    try {
      subP();
    }
    catch (Exception ex)
    {
      Console.WriteLine(ex.Message + ex.StackTrace);
    }
  }

  static void subP()
  {
    try {
      int J = 1 - 1;
      J /= J;
    }
    catch
    {
      Console.WriteLine("Do Something");
      throw;
    }
  }
}
