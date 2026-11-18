# SEPForge

**Apple Secure Enclave architecture and security research — reproducible educational labs.**

SEPForge studies documented Apple Secure Enclave concepts, builds *independent teaching models*, and tests security properties on researcher-owned systems. It does **not** include Apple firmware, proprietary code, or a SEP exploit.

## Start on Apple Silicon macOS

```sh
xcode-select --install  # only if developer tools are missing
uname -m                 # arm64 expected
clang --version
lldb --version
make lab01
make test
```

The intentionally vulnerable Lab 01 sample is for isolated, local instruction only. It is not run by the default `make lab01` or CI test targets.

## Repository map

- `architecture/`: architecture notes and trust boundaries
- `labs/`: hands-on labs, each with README, source, expected observations and tests
- `src/`: reusable models and tooling
- `hardware/`: board-specific experiments and safety notes
- `tests/`: automated regression tests
- `docs/`: research notes, evidence, threat models, references and report templates
- `.github/`: CI and contribution templates

## Roadmap

| Lab | Subject | Deliverable |
|---|---|---|
| 01 | ARM64 registers, stack, LLDB, memory safety | C demos, ASan, remediation |
| 02 | Signed boot chain | toy firmware signature verifier |
| 03 | Microkernel boundaries | isolated message-passing model |
| 04 | Mailbox parsing | parser and fuzz harness |
| 05 | Key management | Swift CryptoKit Secure Enclave demo |
| 06 | Memory protection | authenticated memory simulation |
| 07 | Fault models | owned development board experiments |
| 08 | Security assessment | public-API configuration auditor |

## Research standards

Every claim must be marked **Official**, **Third-party research**, **Observed**, or **Hypothesis**. Record hardware/OS/tool versions, exact commands, expected vs actual outcomes, and limits of inference. Apple Silicon application processor observations do not automatically describe the SEP CPU.

See [research method](docs/methodology.md), [roadmap](docs/roadmap.md), and [disclosure policy](SECURITY.md).

## License

MIT for original code and documentation; external material retains its own license.
