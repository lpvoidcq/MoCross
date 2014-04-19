package org.mo.core.monitor;

import org.mo.core.monitor.common.IMonitor;

//============================================================
// <T>监视器控制台接口。</T>
//============================================================
public interface IMonitorConsole
{
   //============================================================
   // <T>注册一个监视器。</T>
   //
   // @param monitor 监视器
   //============================================================
   void register(IMonitor monitor);

   //============================================================
   // <T>注销一个监视器。</T>
   //
   // @param monitor 监视器
   //============================================================
   void unregister(IMonitor monitor);

   //============================================================
   // <T>等待结束。</T>
   //============================================================
   void waitStop();
}