package org.mo.web.core.webform.control;

import org.mo.com.xml.IXmlObject;

//============================================================
// <T>网格接口对象的XML节点基类。</T>
//============================================================
public interface XGridFace
      extends IXmlObject
{
   // 名称定义
   String NAME = "MGrid";

   // 面板权限的名称定义
   String PTY_PANEL_ACCESS = "panel_access";

   // 行工具栏的名称定义
   String PTY_DISP_ROWBAR = "disp_rowbar";

   // 显示标题栏的名称定义
   String PTY_PANEL_TITLE = "panel_title";

   // 显示表头栏的名称定义
   String PTY_PANEL_HEAD = "panel_head";

   // 显示搜索框栏的名称定义
   String PTY_PANEL_SEARCH = "panel_search";

   // 显示提示栏的名称定义
   String PTY_PANEL_HINT = "panel_hint";

   // 合计的名称定义
   String PTY_PANEL_TOTAL = "panel_total";

   // 准备查询的名称定义
   String PTY_QUERY_PREPARE = "query_prepare";

   // 是否已关联详细表单的名称定义
   String PTY_FORM_LINKED = "form_linked";

   // 传输方式的名称定义
   String PTY_FORM_CUSTOM = "form_custom";

   // 传输参数的名称定义
   String PTY_FORM_PARAMETER = "form_parameter";

   // 显示行选中的名称定义
   String PTY_DISP_SELECTED = "disp_selected";

   //============================================================
   // <T>获得面板权限的内容。</T>
   //
   // @return 面板权限
   //============================================================
   String getPanelAccess();

   //============================================================
   // <T>设置面板权限的内容。</T>
   //
   // @param value 面板权限
   //============================================================
   void setPanelAccess(String value);


   //============================================================
   // <T>获得行工具栏的内容。</T>
   //
   // @return 行工具栏
   //============================================================
   String getDispRowbar();

   //============================================================
   // <T>设置行工具栏的内容。</T>
   //
   // @param value 行工具栏
   //============================================================
   void setDispRowbar(String value);

   //============================================================
   // <T>获得显示标题栏的内容。</T>
   //
   // @return 显示标题栏
   //============================================================
   String getPanelTitle();

   //============================================================
   // <T>设置显示标题栏的内容。</T>
   //
   // @param value 显示标题栏
   //============================================================
   void setPanelTitle(String value);

   //============================================================
   // <T>获得显示表头栏的内容。</T>
   //
   // @return 显示表头栏
   //============================================================
   String getPanelHead();

   //============================================================
   // <T>设置显示表头栏的内容。</T>
   //
   // @param value 显示表头栏
   //============================================================
   void setPanelHead(String value);

   //============================================================
   // <T>获得显示搜索框栏的内容。</T>
   //
   // @return 显示搜索框栏
   //============================================================
   String getPanelSearch();

   //============================================================
   // <T>设置显示搜索框栏的内容。</T>
   //
   // @param value 显示搜索框栏
   //============================================================
   void setPanelSearch(String value);

   //============================================================
   // <T>获得显示提示栏的内容。</T>
   //
   // @return 显示提示栏
   //============================================================
   String getPanelHint();

   //============================================================
   // <T>设置显示提示栏的内容。</T>
   //
   // @param value 显示提示栏
   //============================================================
   void setPanelHint(String value);

   //============================================================
   // <T>获得合计的内容。</T>
   //
   // @return 合计
   //============================================================
   String getPanelTotal();

   //============================================================
   // <T>设置合计的内容。</T>
   //
   // @param value 合计
   //============================================================
   void setPanelTotal(String value);

   //============================================================
   // <T>获得准备查询的内容。</T>
   //
   // @return 准备查询
   //============================================================
   String getQueryPrepare();

   //============================================================
   // <T>设置准备查询的内容。</T>
   //
   // @param value 准备查询
   //============================================================
   void setQueryPrepare(String value);

   //============================================================
   // <T>获得是否已关联详细表单的内容。</T>
   //
   // @return 是否已关联详细表单
   //============================================================
   Boolean getFormLinked();

   //============================================================
   // <T>设置是否已关联详细表单的内容。</T>
   //
   // @param value 是否已关联详细表单
   //============================================================
   void setFormLinked(Boolean value);

   //============================================================
   // <T>获得传输方式的内容。</T>
   //
   // @return 传输方式
   //============================================================
   String getFormCustom();

   //============================================================
   // <T>设置传输方式的内容。</T>
   //
   // @param value 传输方式
   //============================================================
   void setFormCustom(String value);

   //============================================================
   // <T>获得传输参数的内容。</T>
   //
   // @return 传输参数
   //============================================================
   String getFormParameter();

   //============================================================
   // <T>设置传输参数的内容。</T>
   //
   // @param value 传输参数
   //============================================================
   void setFormParameter(String value);

   //============================================================
   // <T>获得显示行选中的内容。</T>
   //
   // @return 显示行选中
   //============================================================
   String getDispSelected();

   //============================================================
   // <T>设置显示行选中的内容。</T>
   //
   // @param value 显示行选中
   //============================================================
   void setDispSelected(String value);
}