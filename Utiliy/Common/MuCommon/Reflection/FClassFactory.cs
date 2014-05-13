﻿using MO.Common.Collection;
using MO.Common.Lang;

namespace MO.Common.Reflection
{
   //============================================================
   // <T>类对象工厂。</T>
   //============================================================
   public class FClassFactory : FObject
   {
      // 类集合
      protected FDictionary<FClass> _classes = new FDictionary<FClass>();

      //============================================================
      // <T>获得类集合。</T>
      //============================================================
      public FClassFactory(){
      }

      //============================================================
      // <T>获得类集合。</T>
      //============================================================
      public FDictionary<FClass> Classes {
         get { return _classes; }
      }
   }
}