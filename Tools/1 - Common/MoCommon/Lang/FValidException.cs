namespace MO.Common.Lang
{
   //============================================================
   // <T>校验例外。</T>
   //============================================================
   public class FValidException : FException
   {
      //============================================================
      // <T>构造校验例外。</T>
      //============================================================
      public FValidException() {
      }

      //============================================================
      // <T>构造校验例外。</T>
      //
      // @param message 消息对象
      // @param args 参数集合
      //============================================================
      public FValidException(object message, params object[] args)
         : base(message, args) {
      }
   }
}