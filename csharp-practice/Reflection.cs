using System;
using System.Reflection;

class Program
{
  class ReflectionTestClass
  {
    internal string member1;
    internal string member2;
    internal void EnumMember()
    {
      Type TypeInfo = this.GetType();

      FieldInfo[] Fields = TypeInfo.GetFields(
          BindingFlags 
          )
    }
  }
}
