type style = ReactDOMRe.Style.t;
type element = React.element;

module Breadcrumb = {
  [@bs.module "antd"] [@react.component]
  external make:
    (~ariaLabel: string=?, ~key: string=?, ~style: style=?, ~children: 'b) =>
    element =
    "Breadcrumb";

  module Item = {
    [@bs.module "antd"] [@bs.scope "Breadcrumb"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~className: string=?,
        ~href: string=?,
        ~style: style=?,
        ~onClick: 'event => unit=?,
        ~children: 'b
      ) =>
      element =
      "Item";
  };
};

module Button = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~ariaLabel: string=?,
      ~key: string=?,
      ~style: style=?,
      ~children: 'b=?,
      ~disabled: bool=?,
      ~ghost: bool=?,
      ~href: string=?,
      ~htmlType: string=?,
      ~icon: string=?,
      ~loading: bool=?,
      ~shape: string=?,
      ~size: string=?,
      ~target: string=?,
      ~_type: string=?,
      ~onClick: 'a => unit=?,
      ~block: bool=?
    ) =>
    element =
    "Button";
};

module Form = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~form: 'a=?,
      ~hideRequiredMark: bool=?,
      ~labelAlign: [@bs.string] [ | `left | `right]=?,
      ~labelCol: 'b=?,
      ~layout: [@bs.string] [ | `horizontal | `vertical | `inline]=?,
      ~onSubmit: 'c => unit=?,
      ~wrapperCol: 'd=?,
      ~colon: bool=?,
      ~children: 'e
    ) =>
    element =
    "Form";
};

module Icon = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~ariaLabel: string=?,
      ~key: string=?,
      ~_type: string,
      ~style: style=?,
      ~theme: [@bs.string] [ | `filled | `outlined | `twoTone]=?,
      ~spin: bool=?,
      ~rotate: int=?,
      ~twoToneColor: string=?
    ) =>
    element =
    "Icon";
};

module Input = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~ariaLabel: string=?,
      ~key: string=?,
      ~_type: [@bs.string] [
                | `button
                | `checkbox
                | `color
                | `date
                | `datetimeLocal
                | [@bs.as "datetime-local"] `email
                | `file
                | `hidden
                | `image
                | `month
                | `number
                | `password
                | `radio
                | `range
                | `reset
                | `search
                | `submit
                | `tel
                | `text
                | `time
                | `url
                | `week
              ],
      ~addonAfter: element=?,
      ~addonBefore: element=?,
      ~defaultValue: string=?,
      ~disabled: bool=?,
      ~id: string=?,
      ~prefix: element=?,
      ~size: string=?,
      ~suffix: element=?,
      ~placeholder: string=?,
      ~value: string=?,
      ~onChange: 'a => unit=?,
      ~onPressEnter: 'a => unit=?,
      ~allowClear: bool=?
    ) =>
    element =
    "Input";

  module Group = {
    [@bs.module "antd"] [@bs.scope "Input"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~children: 'b,
        ~compact: bool=?,
        ~size: [@bs.string] [ | `default | `small | `large]=?
      ) =>
      element =
      "Group";
  };

  module Password = {
    [@bs.module "antd"] [@bs.scope "Input"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~children: 'b,
        ~visibilityToggle: bool=?
      ) =>
      element =
      "Password";
  };

  module Search = {
    [@bs.module "antd"] [@bs.scope "Input"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~_type: string,
        ~addonAfter: element=?,
        ~addonBefore: element=?,
        ~defaultValue: string=?,
        ~disabled: bool=?,
        ~id: string=?,
        ~prefix: element=?,
        ~size: string=?,
        ~suffix: element=?,
        ~value: string=?,
        ~onChange: 'a => unit=?,
        ~onPressEnter: 'a => unit=?,
        ~allowClear: bool=?,
        ~children: 'b,
        ~enterButton: bool=?,
        ~onSearch: (string, 'a) => unit=?
      ) =>
      element =
      "Search";
  };

  module TextArea = {
    [@bs.module "antd"] [@bs.scope "Input"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~children: 'b,
        ~autosize: bool=?,
        ~defaultValue: string=?,
        ~value: string=?,
        ~onPressEnter: 'a => unit=?
      ) =>
      element =
      "TextArea";
  };
};

module Layout = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~ariaLabel: string=?,
      ~key: string=?,
      ~className: string=?,
      ~hasSider: bool=?,
      ~style: style=?,
      ~children: 'b
    ) =>
    element =
    "Layout";

  module Header = {
    [@bs.module "antd"] [@bs.scope "Layout"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~className: string=?,
        ~style: style=?,
        ~children: 'b
      ) =>
      element =
      "Header";
  };

  module Content = {
    [@bs.module "antd"] [@bs.scope "Layout"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~className: string=?,
        ~hasSider: bool=?,
        ~style: style=?,
        ~children: 'b
      ) =>
      element =
      "Content";
  };

  module Footer = {
    [@bs.module "antd"] [@bs.scope "Layout"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~className: string=?,
        ~style: style=?,
        ~children: 'b
      ) =>
      element =
      "Footer";
  };

  module Sider = {
    [@bs.module "antd"] [@bs.scope "Layout"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~breakpoint: [@bs.string] [ | `xs | `sm | `md | `lg | `xl | `xxl]=?,
        ~className: string=?,
        ~collapsed: bool=?,
        ~collapsedWidth: int=?,
        ~collapsible: bool=?,
        ~defaultCollapsed: bool=?,
        ~reverseArrow: bool=?,
        ~style: style=?,
        ~theme: [@bs.string] [ | `light | `dark]=?,
        ~trigger: string=?,
        ~width: int=?,
        ~onCollapse: ('a, 'b) => unit=?,
        ~onBreakpoint: 'a => unit=?,
        ~children: 'b=?
      ) =>
      element =
      "Sider";
  };
};

module Menu = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~ariaLabel: string=?,
      ~key: string=?,
      ~defaultOpenKeys: array(string)=?,
      ~defaultSelectedKeys: array(string)=?,
      ~forceSubMenuRender: bool=?,
      ~inlineCollapsed: bool=?,
      ~inlineIndent: int=?,
      ~mode: [@bs.string] [ | `vertical | `horizontal | `inline]=?,
      ~multiple: bool=?,
      ~openKeys: array(string)=?,
      ~selectable: bool=?,
      ~selectedKeys: array(string)=?,
      ~style: style=?,
      ~subMenuCloseDelay: int=?,
      ~subMenuOpenDelay: int=?,
      ~theme: [@bs.string] [ | `light | `dark]=?,
      ~onClick: {
                  ..
                  "item": 'a,
                  "key": string,
                  "keyPath": string,
                  "domEvent": 'b,
                } =>
                unit
                  =?,
      ~onDeselect: {
                     ..
                     "item": 'a,
                     "key": string,
                     "keyPath": string,
                     "domEvent": 'b,
                     "selectedKeys": array(string),
                   } =>
                   unit
                     =?,
      ~onOpenChange: {.. "openKeys": array(string)} => unit=?,
      ~onSelect: {
                   ..
                   "item": 'a,
                   "key": string,
                   "keyPath": string,
                   "domEvent": 'b,
                   "selectedKeys": array(string),
                 } =>
                 unit
                   =?,
      ~overflowedIndicator: element=?,
      ~children: 'b=?
    ) =>
    element =
    "Menu";

  module SubMenu = {
    [@bs.module "antd"] [@bs.scope "Menu"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~popupClassName: string=?,
        ~disabled: bool=?,
        ~title: element=?,
        ~onTitleClick: {
                         ..
                         "key": string,
                         "domEvent": 'b,
                       } =>
                       unit
                         =?,
        ~children: 'b=?
      ) =>
      element =
      "SubMenu";
  };

  module ItemGroup = {
    [@bs.module "antd"] [@bs.scope "Menu"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~title: element=?,
        ~children: 'b=?
      ) =>
      element =
      "ItemGroup";
  };

  module Item = {
    [@bs.module "antd"] [@bs.scope "Menu"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~disabled: bool=?,
        ~title: string=?,
        ~children: 'b
      ) =>
      element =
      "Item";
  };
};

module Select = {
  type selectOption;

  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~allowClear: bool=?,
      ~autoClearSearchValue: bool=?,
      ~autoFocus: bool=?,
      ~defaultActiveFirstOption: bool=?,
      ~defaultValue: 'a=?,
      ~disabled: bool=?,
      ~dropdownClassName: string=?,
      ~dropdownMatchSelectWidth: bool=?,
      ~dropdownRender: ({.. "menuNode": element}, 'b) => element=?,
      ~dropdownStyle: style=?,
      ~filterOption: ('a, selectOption)=?,
      ~firstActiveValue: array(string)=?,
      ~labelInValue: bool=?,
      ~maxTagCount: int=?,
      ~maxTagTextLength: int=?,
      ~maxTagPlaceholder: element=?,
      ~mode: [@bs.string] [ | `default | `multiple | `tags]=?,
      ~notFoundContent: string=?,
      ~optionFilterProp: string=?,
      ~optionLabelProp: string=?,
      ~placeholder: element=?,
      ~showArrow: bool=?,
      ~showSearch: bool=?,
      ~size: string=?,
      ~suffixIcon: element=?,
      ~removeIcon: element=?,
      ~clearIcon: element=?,
      ~menuItemSelectedIcon: element=?,
      ~tokenSeparators: array(string)=?,
      ~value: 'a=?,
      ~onBlur: unit => unit=?,
      ~onChange: 'a => unit=?,
      ~onDeselect: 'a => unit=?,
      ~onFocus: unit => unit=?,
      ~onInputKeyDown: 'k => unit=?,
      ~onMouseEnter: 'm => unit=?,
      ~onMouseLeave: 'm => unit=?,
      ~onPopupScroll: 'm => unit=?,
      ~onSearch: string => unit=?,
      ~onSelect: ('a, selectOption)=?,
      ~defaultOpen: bool=?,
      ~_open: bool=?,
      ~onDropdownVisibleChange: bool => unit=?,
      ~style: style=?,
      ~loading: bool=?,
      ~children: 'b=?
    ) =>
    element =
    "Select";

  module Option = {
    [@bs.module "antd"] [@bs.scope "Select"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~disabled: bool=?,
        ~title: string=?,
        ~value: string=?,
        ~className: string=?,
        ~children: 'b=?
      ) =>
      element =
      "Option";
  };

  module OptGroup = {
    [@bs.module "antd"] [@bs.scope "Select"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~label: element=?,
        ~children: 'b=?
      ) =>
      element =
      "OptGroup";
  };
};

module Table = {
  module Column = {
    [@bs.deriving abstract]
    type props('a, 'b, 'dataSource) = {
      [@bs.optional]
      align: [@bs.string] [ | `left | `right | `center],
      [@bs.optional]
      ariaLabel: string,
      [@bs.optional]
      key: string,
      [@bs.optional]
      children: 'b,
      [@bs.optional]
      className: string,
      [@bs.optional]
      colSpan: int,
      [@bs.optional]
      dataIndex: string,
      [@bs.optional]
      defaultSortOrder: [@bs.string] [ | `ascend | `descend],
      [@bs.optional]
      filterDropdown: element,
      [@bs.optional]
      filterDropdownVisible: bool,
      [@bs.optional]
      filtered: bool,
      [@bs.optional]
      filteredValue: array(string),
      [@bs.optional]
      filterIcon: element,
      [@bs.optional]
      filterMultiple: bool,
      /* filters:object[], */
      [@bs.optional]
      fixed: [@bs.string] [ | `left | `right],
      [@bs.optional]
      render: (string, 'dataSource, int) => element,
      [@bs.optional]
      sorter: ('dataSource, 'dataSource) => int,
      [@bs.optional]
      sortOrder: [@bs.string] [ | `ascend | `descend],
      [@bs.optional]
      sortDirections: string,
      [@bs.optional]
      title: element,
      [@bs.optional]
      width: string,
      /* onCell:Function(record, rowIndex), */
      [@bs.optional]
      onFilter: 'a => unit,
      [@bs.optional]
      onFilterDropdownVisibleChange: bool => unit,
      [@bs.optional]
      onHeaderCell: 'b => unit,
    };
  };

  [@bs.deriving abstract]
  type onRowHandler('a) = {
    [@bs.optional]
    onClick: 'a => unit, /* click row */
    [@bs.optional]
    onDoubleClick: 'a => unit, /* double click row */
    [@bs.optional]
    onContextMenu: 'a => unit, /* right button click row */
    [@bs.optional]
    onMouseEnter: 'a => unit, /* mouse enter row */
    [@bs.optional]
    onMouseLeave: 'a => unit /* mouse leave row */
  };

  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~bordered: bool=?,
      ~childrenColumnName: array(string)=?,
      ~columns: array(Column.props('cpa, 'cpb, 'dataSource))=?,
      /* ~components:TableComponents=?, */
      ~dataSource: array('datasource)=?,
      ~defaultExpandAllRows: bool=?,
      ~defaultExpandedRowKeys: array(string)=?,
      ~expandedRowKeys: array(string)=?,
      ~expandedRowRender: ('dataSource, int, int, bool) => element=?,
      /* ~expandIcon:Function(props):ReactNode=?, */
      ~expandRowByClick: bool=?,
      ~footer: 'currentPageData => element=?,
      ~indentSize: int=?,
      ~loading: bool=?,
      ~locale: {
                 ..
                 "filterTitle": string,
                 "filterConfirm": string,
                 "filterReset": string,
                 "emptyText": string,
               }
                 =?,
      ~pagination: {.. "position": string}=?,
      /* ~rowClassName:Function(record, index):string=?, */
      ~rowKey: 'datasource => string=?,
      /* ~rowSelection:object=?, */
      ~scroll: {
                 .
                 "x": int,
                 "y": int,
               }
                 =?,
      ~showHeader: bool=?,
      ~size: [@bs.string] [ | `default | `middle | `small]=?,
      ~title: 'currentPageData => element=?,
      ~onRow: ('dataSource, int) => onRowHandler('mouseEvent)=?
    ) =>
    /* ~onChange:Function(pagination, filters, sorter, extra: { currentDataSource: [] })=?, */
    /* ~onExpand:Function(expanded, record)=?, */
    /* ~onExpandedRowsChange:Function(expandedRows)=?, */
    /* ~onHeaderRow:Function(column, index)=?, */
    /* ~getPopupContainer:(triggerNode) => HTMLElement=?, */
    element =
    "Table";

  module ColumnGroup = {
    [@bs.module "antd"] [@bs.scope "Table"] [@react.component]
    external make:
      (
        ~ariaLabel: string=?,
        ~key: string=?,
        ~children: 'b=?,
        ~title: string=?
      ) =>
      element =
      "ColumnGroup";
  };
};

module Message = {
  [@bs.module "antd"] [@bs.scope "message"]
  external success:
    (
      ~content: element,
      ~duration: int=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      unit
    ) =>
    unit =
    "success";

  [@bs.module "antd"] [@bs.scope "message"]
  external info:
    (
      ~content: element,
      ~duration: int=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      unit
    ) =>
    unit =
    "info";

  [@bs.module "antd"] [@bs.scope "message"]
  external warning:
    (
      ~content: element,
      ~duration: int=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      unit
    ) =>
    unit =
    "warning";

  [@bs.module "antd"] [@bs.scope "message"]
  external warn:
    (
      ~content: element,
      ~duration: int=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      unit
    ) =>
    unit =
    "warn";

  [@bs.module "antd"] [@bs.scope "message"]
  external loading:
    (
      ~content: element,
      ~duration: int=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      unit
    ) =>
    unit =
    "loading";

  [@bs.module "antd"] [@bs.scope "message"]
  external error:
    (
      ~content: element,
      ~duration: int=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      unit
    ) =>
    unit =
    "error";
};

module Popconfirm = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~ariaLabel: string=?,
      ~key: string=?,
      ~cancelText: string=?,
      ~okText: string=?,
      ~okType: string=?,
      ~title: element=?,
      ~onCancel: unit => unit=?,
      ~onConfirm: unit => unit=?,
      ~icon: element=?,
      ~disabled: bool=?,
      ~children: 'b=?
    ) =>
    element =
    "Popconfirm";
};

module Card = {
  [@bs.module "antd"] [@react.component]
  external make:
    (
      ~actions: array(element)=?,
      ~activeTabKey: string=?,
      ~headStyle: style=?,
      ~bodyStyle: style=?,
      ~bordered: bool=?,
      ~cover: element=?,
      ~defaultActiveTabKey: string=?,
      ~extra: string=?,
      ~hoverable: bool=?,
      ~loading: bool=?,
      /* ~tabList:	Array<{key: string, tab: ReactNode}>, */
      /* ~tabBarExtraContent:	React.ReactNode, */
      ~size: string=?,
      ~title: string=?,
      ~_type: string=?,
      ~children: 'b
    ) =>
    element =
    "Card";
};
