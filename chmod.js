const fs = require('fs');
const { execFile } = require('child_process');

fs.open('haha.sh', 'w', (err, fd) => {
    fs.writeFile('haha.sh', "echo 'haha'", (err, data) => {
        if (err) {
            console.log(err);
            return;
        }
        fs.closeSync(fd);
        fs.chmod('haha.sh', 0o777, (err) => {
            if (err) {
                console.log(err, 'err');
                return;
            }
            execFile('node', ['--version'], (err, stdout, stderr) => {
                if (err) {
                    console.log(err, 'err');
                }
                console.log(stdout, 'stdout');
                console.log(stderr, 'stderr');
            });
        })
    });
});
