{
    "targets": [
        {
            "target_name": "addon",
            "sources": [ "add-on.cpp" ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}

