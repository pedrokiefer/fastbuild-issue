# Repository for bazel issue #3061

1. Clone repository
1. Run `bazel build --config=arm //src:network`
1. Build fails

bazel version
```
Build label: 0.5.0
Build target: bazel-out/local-fastbuild/bin/src/main/java/com/google/devtools/build/lib/bazel/BazelServer_deploy.jar
Build time: Fri May 26 12:11:50 2017 (1495800710)
Build timestamp: 1495800710
Build timestamp as int: 1495800710
```

## Fastbuild fails
```
bazel build --config=arm //src:network
INFO: Analysed target //src:network.
INFO: Found 1 target...
ERROR: /home/pedro/Projects/fastbuild-issue/src/BUILD:1:1: undeclared inclusion(s) in rule '//src:network':
this rule is missing dependency declarations for the following files included by 'src/a.cpp':
  '/home/pedro/.cache/bazel/_bazel_pedro/614fa825e24ef127fa3611539930859d/external/org_openwrt_libubox/list.h'
  '/home/pedro/.cache/bazel/_bazel_pedro/614fa825e24ef127fa3611539930859d/external/org_openwrt_libubox/blob.h'
  '/home/pedro/.cache/bazel/_bazel_pedro/614fa825e24ef127fa3611539930859d/external/org_openwrt_libubox/utils.h'
  '/home/pedro/.cache/bazel/_bazel_pedro/614fa825e24ef127fa3611539930859d/external/org_openwrt_libubox/blobmsg.h'
Target //src:network failed to build
Use --verbose_failures to see the command lines of failed build steps.
INFO: Elapsed time: 1.399s, Critical Path: 1.10s
FAILED: Build did NOT complete successfully
```

## OPT and DBG builds

```
bazel build --config=arm //src:network -c opt
INFO: Analysed target //src:network.
INFO: Found 1 target...
Target //src:network up-to-date:
  bazel-bin/src/libnetwork.a
  bazel-bin/src/libnetwork.pic.a
INFO: Elapsed time: 5.804s, Critical Path: 4.26s
INFO: Build completed successfully, 60 total actions
```

```
bazel build --config=arm //src:network -c dbg
INFO: Analysed target //src:network.
INFO: Found 1 target...
Target //src:network up-to-date:
  bazel-bin/src/libnetwork.a
INFO: Elapsed time: 4.777s, Critical Path: 2.04s
INFO: Build completed successfully, 57 total actions
```
