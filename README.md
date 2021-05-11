All header files from 

`/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk`

ignored file types:

```
*.a
*.bitstream
*.tbd
*.swiftdoc
*.swiftinterface
*.swiftoverlay
```

update for every system version.
- 格式化 iPhoneOS.sdk/SDKSettings.json
- 检查更新的文件是否包含非text可读文件
```
^[ \t\S]+.h$\n
^[ \t\S]+c\+\++[ \t\S]+\n
```