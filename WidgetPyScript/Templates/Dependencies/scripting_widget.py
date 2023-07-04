import functools
import xml.etree.ElementTree as ET
import re
import unreal

def get_xml_root(xml_path:str):
    with open(xml_path) as file:
        xml_text = file.read()
    try:
        root = ET.fromstring(re.sub(r"(<\?xml[^>]+\?>)", r"\1<root>", xml_text) + "</root>")
        return root
    except ET.ParseError as err:
        print('Invalid XML file. Please check the text format.\nUnexpected {} : {}'.format(type(err).__name__, err))

def get_xml_header_value(root:ET.Element, tag:str):
    if root:
        header = root.find('header')
        if header:
            try:
                return header.find(tag).text
            except AttributeError:
                return
        else:
            print('Node "header" doesn\'t exist in XML file')
    return

def iterate_xml_widgets(root:ET.Element):
    if root:
        body = root.find('body')
        if body:
            for child in body:
                if child.tag == 'widget_element':
                    yield child
        else:
            print('Node "body" doesn\'t exist in XML file')
    return

def get_xml_widget_property(widget_element:ET.Element, tag:str):
    if widget_element:
        try:
            return widget_element.find(tag).text
        except AttributeError:
            return
    return


class ScriptingWidgetBase(object):
    def __init__(self, asset_path):
        self.widget_BP = unreal.load_asset(asset_path)
        self.widget_id = None
        self.ui = None
    
    def __post_init__(self):
        pass

    def show(self):
        editor_sub = unreal.get_editor_subsystem(unreal.EditorUtilitySubsystem)
        widget, self.widget_id = editor_sub.spawn_and_register_tab_and_get_id(self.widget_BP)
    
    def close(self):
        if self.widget_id:
            editor_sub = unreal.get_editor_subsystem(unreal.EditorUtilitySubsystem)
            editor_sub.close_tab_by_id(self.widget_id)
            self.widget_id = None


# decorator
def singleton(cls):
    """Make a class a Singleton class (only one instance)"""
    @functools.wraps(cls)
    def wrapper_singleton(*args, **kwargs):
        if not wrapper_singleton.instance:
            wrapper_singleton.instance = cls(*args, **kwargs)
        return wrapper_singleton.instance
    wrapper_singleton.instance = None
    return wrapper_singleton


def widgetXML(xml_path:str):
    def decorator_widget(cls):
        class ScriptingWidgetUIBase(object):
            pass

        @functools.wraps(cls)
        def wrapper_widget(*args, **kwargs):
            xml_root = get_xml_root(xml_path)
            asset_name = get_xml_header_value(xml_root, 'asset_name')
            asset_path = get_xml_header_value(xml_root, 'asset_path')
            widget_asset_obj = cls(asset_path, *args, **kwargs)
            ui_object = ScriptingWidgetUIBase()
            for widget_element in iterate_xml_widgets(xml_root):
                widget_name = widget_element.get('name')
                widget_BP = unreal.load_asset(asset_path)
                widget_object = unreal.find_object(None, '{}_C:WidgetTree.{}'.format(asset_path, widget_name))
                ui_object.__setattr__(widget_name, widget_object)
            widget_asset_obj.ui = ui_object
            widget_asset_obj.__post_init__()
            return widget_asset_obj
        if ScriptingWidgetBase not in cls.__bases__:
            raise TypeError('Class {} with decorator widgetXML doesn\'t inherit class ScriptingWidgetBase'
                            .format(cls.__name__))
        return wrapper_widget
    return decorator_widget


# @widgetXML('E:\MyProject\PyWidget\Plugins\WidgetPyScript\Templates\Dependencies\Test_BP.xml')
# class Example(ScriptingWidgetBase):
#     def __post_init__(self):
#         super().__post_init__()
#         self.ui.Button_test.on_clicked.add_callable(lambda:print("button click"))

# a=Example()
# a.show()
# a.close()