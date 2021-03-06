package mo.android.common;

import android.content.Context;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;
import mo.android.api.RNativeApi;

//============================================================
// <T>表面视图。</T>
//============================================================
public class FSurfaceView
      extends GLSurfaceView
{
   protected FSurfaceContextFactory _contextFactory = new FSurfaceContextFactory();

   protected FSurfaceRender _render = new FSurfaceRender();

   //============================================================
   // <T>构造表面视图。</T>
   //============================================================
   public FSurfaceView(Context context){
      super(context);
      init(false, 0, 0);
   }

   //============================================================
   // <T>构造表面视图。</T>
   //============================================================
   public FSurfaceView(Context context,
                       boolean translucent,
                       int depth,
                       int stencil){
      super(context);
      init(translucent, depth, stencil);
   }

   //============================================================
   // <T>初始化处理。</T>
   //============================================================
   private void init(boolean translucent,
                     int depth,
                     int stencil){
      if(translucent){
         getHolder().setFormat(PixelFormat.TRANSLUCENT);
      }
      setEGLContextClientVersion(2);
      setEGLContextFactory(_contextFactory);
      FSurfaceConfigChooser chooser = null;
      if(translucent){
         chooser = new FSurfaceConfigChooser(8, 8, 8, 8, depth, stencil);
      }else{
         chooser = new FSurfaceConfigChooser(5, 6, 5, 0, depth, stencil);
      }
      setEGLConfigChooser(chooser);
      setRenderer(_render);
   }

   //============================================================
   // <T>响应鼠标事件。</T>
   //============================================================
   @Override
   public boolean onTouchEvent(MotionEvent event){
      int actionCd = event.getAction();
      switch(actionCd){
         case MotionEvent.ACTION_DOWN:{
            // 鼠标落下处理
            float x = event.getX();
            float y = event.getY();
            RNativeApi.onMouseDown(0, x, y);
            return true;
         }
         case MotionEvent.ACTION_MOVE:{
            // 鼠标落下处理
            float x = event.getX();
            float y = event.getY();
            RNativeApi.onMouseMove(0, x, y);
            return true;
         }
         case MotionEvent.ACTION_UP:{
            // 鼠标落下处理
            float x = event.getX();
            float y = event.getY();
            RNativeApi.onMouseUp(0, x, y);
            return true;
         }
      }
      return super.onTouchEvent(event);
   }
}
