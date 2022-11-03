const data = {
    "pageArray": ["general", "appearance"],
    "general": {
        "category01": "Activation",
        "option01": {
            "title": "Timeout duration",
            "description": "Time till the flyout would hide after activation",
            "type": "text",
            "rmvariable": "BoolVariable"
        },
        "option02": {
            "title": "Activate flyouts with a hotkey",
            "description": "Turn on an additional hotkey to launch flyouts",
            "type": "bool",
            "rmvariable": "BoolVariable"
        },
        "category02": "Flyout components",
        "option04": {
            "title": "Enable CapsLock / NumLock / ScrollLock Flyouts",
            "description": "",
            "type": "Bool",
            "rmvariable": "BoolVariable"
        },
        "option05": {
            "title": "Enable Media Flyouts",
            "description": "",
            "type": "bool",
            "rmvariable": "BoolVariable"
        },
        "category03": "Compatability",
        "option06": {
            "title": "Use legacy volume key hooks",
            "description": "Uses AHK to detect if you've changed volume instead of using the Windows interface",
            "type": "Bool",
            "rmvariable": "BoolVariable"
        },
        "option07": {
            "title": "Volume tick by legacy key hook",
            "description": "Level of volume to change when pressing media keys",
            "type": "text",
            "rmvariable": "BoolVariable"
        },
        "option08": {
            "title": "Use locks key hooks",
            "description": "Uses AHK to detect if you've changed volume instead of listening to key presses",
            "type": "bool",
            "rmvariable": "BoolVariable"
        },
        "option09": {
            "title": "Use legacy force brightness changer",
            "description": "Allows you to change monitor brightness with custom hotkeys",
            "type": "bool",
            "rmvariable": "BoolVariable"
        }
    },
    "appearance": {
        "category01": "Based"
    }
}