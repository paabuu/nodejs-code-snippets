{
    "targets": [
        {
            "target_name": "echo",
            "sources": [ "echo.cc" ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        },
        {
            "target_name": "pet",
            "sources": [ "pet.cc" ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ] 
        }
    ]
}