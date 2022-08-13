using System;
using System.Collections;

class Program
{
  static int[,] AdjacentMatrix =  {{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, //A
                                     { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, //B
                                     { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, //C
                                     { 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 }, //D
                                     { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, //E
                                     { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, //F
                                     { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, //G
                                     { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, //H
                                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, //I
                                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //J
    };

  static void Main() 
  {
    var stk = new Stack<List<int>>();
    List<int> WillPush;


  }
}
