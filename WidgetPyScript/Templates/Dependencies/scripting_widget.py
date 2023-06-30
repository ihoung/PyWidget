import functools
import xml.etree.ElementTree as ET

def get_xml_header_value(tag):
    pass


# decorator
def widgetXML(xml_path):
    def decorator_widget(cls):
        @functools.wraps(cls)
        def wrapper_widget(*args, **kwargs):
            pass
        return wrapper_widget
    return decorator_widget