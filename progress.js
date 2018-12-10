/**
 * 模拟npm等程序的安装进度条
 */

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('continue?(Y/n)', answer => {
    if (answer === 'Y') {
        let percent = 0;
        const timer = setInterval(() => {
            if (percent > 10) {
                clearInterval(timer);
                rl.prompt();
                rl.write('done.');
                rl.close();
                return;
            }

            const output = `${'#'.repeat(percent)} ${' '.repeat(10 - percent)}${percent * 10}%`;
            const line = process.stdout.rows;
            // readline.cursorTo(process.stdout, 0, line);
            rl.write(null, {ctrl: true, name: 'u'});
            rl.write(output);
            percent++;
        }, 300);
    } else {
        console.log('bye~');
        rl.close();
    }
});